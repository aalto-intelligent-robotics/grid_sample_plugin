#ifndef _GRASPIT_INTERFACE_H_
#define _GRASPIT_INTERFACE_H_ 

#include <ros/ros.h>
#include "graspit/plugin.h"
#include <actionlib/server/simple_action_server.h>

#include "graspit/robot.h"
// ActionServer includes
#include <grid_sample_msgs/GridSampleAction.h>

class Robot;

namespace GridSamplerNode
{

    class GridSamplerNode : public Plugin
    {

	private:
	    ros::NodeHandle *nh;

	    // ActionServer declarations
	    actionlib::SimpleActionServer<grid_sample_msgs::GridSampleAction> *gridSampleActionServer;

	    //ActionServer callbacks
	    void gridSampleCB(const grid_sample_msgs::GridSampleGoalConstPtr &goal);


	public: 
	    GridSamplerNode(){}
	    ~GridSamplerNode(){}

	    virtual int init(int argc, char **argv);

	    virtual int mainLoop();

    };

}


#endif
