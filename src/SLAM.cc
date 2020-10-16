#include "SLAM.h"

namespace GOSLAM
{
SLAM::SLAM(const string &strVocFile, const string &strSettingsFile, bool verbose)
{
    cv::FileStorage fsSettings(strSettingsFile.c_str(), cv::FileStorage::READ);
    if(!fsSettings.isOpened())
    {
       cerr << "Failed to open settings file at: " << strSettingsFile << endl;
       exit(-1);
    }


}
}
