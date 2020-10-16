#include "SLAM.h"

namespace GOSLAM
{
SLAM::SLAM(const string &strVocFile, const string &strSettingsFile, bool verbose)
{
    cv::FileStorage fSettings(strSettingsFile, cv::FileStorage::READ);
    if(!fSettings.isOpened())
    {
       cerr << "Failed to open settings file at: " << strSettingsFile << endl;
       exit(-1);
    }

    int nFeatures = fSettings["ORBextractor.nFeatures"];
    float fScaleFactor = fSettings["ORBextractor.scaleFactor"];
    int nLevels = fSettings["ORBextractor.nLevels"];
    int fIniThFAST = fSettings["ORBextractor.iniThFAST"];
    int fMinThFAST = fSettings["ORBextractor.minThFAST"];
    mORB = new ORB(nFeatures, fScaleFactor, nLevels, fIniThFAST, fMinThFAST);
}

}
