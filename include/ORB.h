#ifndef _ORB_H_
#define _ORB_H_
#include<vector>
#include<string>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;
namespace GOSLAM
{
class ORBKey 
{
public:
    unsigned int x;
    unsigned int y;
    float strong; 
    ORBKey(double, double ,double, double);
};
class ORBDescriptor
{
public:
   unsigned char data; 
};

class ORB 
{
public:
    ORB();
    ORB(int _nFeatures, float _fscaleFactor, float _nLevels, float _fIniThFAST, float _fMinThFAST);
    void ComputePyramid();
    void ComputeFeatures();
    void ComputeDescriptors();
    void extract();
private:
    // KeyPoint related
    std::vector<ORBKey> mKeyPoints;
    std::vector<int> mnFeaturesPerLevel;
    std::vector<int> umax; // the end of a row in a circular patch

    // Descriptor Related
    std::vector<ORBDescriptor> mDescriptor;
    std::vector<cv::Point> pattern;

    // Scale Releated variables
    double mScaleFactor;
    std::vector<float> mvScaleFactor;
    std::vector<float> mvInvScaleFactor;
    std::vector<cv::Mat> mvImagePyramid;
    // ORB SLAM에서도 안쓰임
    //std::vector<float> mvLevelSigma2;
    //??

    // Basic Configuration
    int nfeatures;
    double scaleFactor;
    float nlevels; 
    float fIniThFAST;
    float fMinThFAST;
};
}
#endif
