#include <vector>

template <typename T> class ScrollBuffer
{
public:
    size_t n_samples;
    size_t n_channels;

    ScrollBuffer(size_t n_channels, size_t n_samples)
    {
        this->n_channels = n_channels;
        this->n_samples = n_samples;

        data = new T[n_channels * n_samples];
        memset((void*)data, 0, sizeof(T) * (n_channels * (n_samples)));
    }

    ~ScrollBuffer()
    {
        delete[] data;
    }

    void appendSample(std::vector<T>& sample)
    {
        memmove(data, data + (n_channels), n_channels * (n_samples - 1) * sizeof(T));
        memcpy(data + (n_channels * (n_samples - 1)), sample.data(), n_channels * sizeof(T));
    }

    void getChannel(size_t ind, std::vector<T>& channel)
    {
        if (ind <= n_channels)
        {
            channel.resize(n_samples);
            for (int i = 0; i < n_samples; ++i)
            {
                channel[i] = data[i * n_channels + ind];
            }
        }
        else
        {
            channel.clear();
        }
    }

    void getChannel(size_t ind, size_t startSample, size_t endSample, std::vector<T>& channel)
    {
        if (ind <= n_channels)
        {
            channel.resize(endSample - startSample+1);
            for (int i = startSample; i <= endSample; ++i)
            {
                channel[i - startSample] = data[i * n_channels + ind];
            }
        }
        else
        {
            channel.clear();
        }
    }

    void getSample(size_t ind, std::vector<T>& sample)
    {
        if (ind <= n_samples)
        {
            sample.resize(n_channels);
            for (int i = 0; i < n_channels; ++i)
            {
                sample[i] = data[ind * n_channels + i];
            }
        }
        else
        {
            sample.clear();
        }
    }

    T* getBuffer(void)
    {
        return data;
    }

    void print(int lastNtoPrint)
    {
        if (n_samples >= lastNtoPrint)
        {
            for (int i = 0; i < n_channels; ++i)
            {
                for (int j = n_samples - lastNtoPrint; j < n_samples; ++j)
                {
                    std::cout << data[j * n_channels + i] << " ";
                }
                std::cout << std::endl;
            }
        }
    }
private:
    T* data;
};