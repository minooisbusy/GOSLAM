#ifndef __FRAME_H__
#define __FRAME_H__ 
#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/xfeatures2d/nonfree.hpp>
#include<opencv2/features2d.hpp>
#include<string>
#include<tuple>
#include<assert.h>
#include<iostream>
#include<cstdlib>
namespace GO_SLAM
{
// Singleton Pattern(Constructor with private attribute)
class FramePublisher
{
public:
    static FramePublisher& instance();
private:
    FramePublisher();
    bool NextFrame();
    const cv::Mat GetFrameData();
    cv::Mat m_im;
    

};
}
#endif
