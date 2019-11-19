# Scrolling buffer #
Simple scrolling buffer implementation I used for multimodal time series applications.
```cpp
#include <iostream>
#include <numeric>
#include "ScrollingBuffer.h"

void main (void)
{
    size_t N_channels=3;
    size_t N_samples = 4;
    ScrollBuffer<int> buff(N_channels, N_samples);
    std::cout << "Just created buffer content:" << std::endl;
    buff.print(N_samples);
    std::cout << "Let's fill it:" << std::endl;
    for (int i = 0; i < N_samples; ++i)
    {
        std::vector<int> sampleVector(N_channels);
        std::iota(sampleVector.begin(), sampleVector.end(), i * N_channels);
        buff.appendSample(sampleVector);
    }
    buff.print(N_samples);
    std::cout << "Let's append 2 more:" << std::endl;
    for (int i = N_samples; i < N_samples+2; ++i)
    {
        std::vector<int> sampleVector(N_channels);
        std::iota(sampleVector.begin(), sampleVector.end(), i * N_channels);
        buff.appendSample(sampleVector);
    }
    buff.print(N_samples);
    std::cout << "Let's get sample (ind = 2):" << std::endl;
    std::vector<int> sampleVector;
    buff.getSample(2, sampleVector);
    std::cout << "[ ";
    for (auto x : sampleVector)
    {
        std::cout << x << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Let's get channel (ind = 1):" << std::endl;
    std::vector<int> channelVector;
    buff.getChannel(1, channelVector);
    std::cout << "[ ";
    for (auto x : channelVector)
    {
        std::cout << x << " ";
    }
    std::cout << "]" << std::endl;
    
    std::cout << "Let's get selected samples (1-2) of channel (ind = 1):" << std::endl;
    buff.getChannel(1, 1, 2, channelVector);
    std::cout << "[ ";
    for (auto x : channelVector)
    {
        std::cout << x << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "And get buffer's data storage:" << std::endl;
    int* data = buff.getBuffer();
    std::cout << "[ ";
    for (int i = 0; i < N_samples* N_channels; ++i)
    {     
        std::cout << data[i] << " ";
    }
    std::cout << "]" << std::endl;
}
```

The code above produces output:

```
Just created buffer content:
0 0 0 0
0 0 0 0
0 0 0 0
Let's fill it:
0 3 6 9
1 4 7 10
2 5 8 11
Let's append 2 more:
6 9 12 15
7 10 13 16
8 11 14 17
Let's get sample (ind = 2):
[ 12 13 14 ]
Let's get channel (ind = 1):
[ 7 10 13 16 ]
Let's get selected samples (1-2) of channel (ind = 1):
[ 10 13 ]
And get buffer's data storage:
[ 6 7 8 9 10 11 12 13 14 15 16 17 ]
```