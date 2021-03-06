#ifndef _SLAM_H_
#define _SLAM_H_
#include<opencv2/opencv.hpp>
#include<string>
#include "ORB.h"
#include "Tracker.h"

using namespace std;
namespace GOSLAM
{

class SLAM
{
public:
    SLAM(const string &strVocFile, const string &strSettingsFile, bool verbose);
    bool Track();
    bool LocalMap();
private:
    //Functional Variables
    ORB *mORB;
    Tracker mTracker;

    // Camera Vairables
    Mat mK;
    Mat mDistCoef;
    float fps;
    

};

}
#endif
