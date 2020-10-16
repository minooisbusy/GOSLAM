#include"Frame.h"

namespace GO_SLAM
{
FramePublisher::FramePublisher(){}
FramePublisher& FramePublisher::instance()
{
    static FramePublisher* instance = new FramePublisher();
    return *instance;
}

}
