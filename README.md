# GoChaseIt-RSE
Project 2 of the Robotics Software Engineering Nanodegree Program at Udacity. 

## Outcomes -->

- Designed a **differential drive robot, with a camera and lidar**, in URDF (Unified Robot Description Format) and housed it in a world different from that in Project 1
- Added Gazebo plugins for the robot’s differential drive capability, lidar, and camera
- Wrote C++ client and server nodes to read the robot's camera image, analyzes it to **determine the presence of a white ball, and drive the robot towards it**

## Directory structure -->

    ├── my_robot                       # my_robot package                   
    │   ├── launch                     # launch folder for launch files   
    │   │   ├── robot_descriptionGoChaseIt.launch
    │   │   ├── worldGoChaseIt.launch
    │   ├── meshes                     # meshes folder for the lidar sensor
    │   │   ├── hokuyo.dae
    │   ├── urdf                       # urdf folder for xarco files
    │   │   ├── my_robotGoChaseIt.gazebo
    │   │   ├── my_robotGoChaseIt.xacro
    │   ├── world                      # world folder for world files
    │   │   ├── homeGoChaseIt.world
    │   ├── CMakeLists.txt             # compiler instructions
    │   ├── package.xml                # package info
    ├── ball_chaser                    # ball_chaser package                   
    │   ├── launch                     # launch folder for launch files   
    │   │   ├── ball_chaser.launch
    │   ├── src                        # source folder for C++ scripts
    │   │   ├── drive_bot.cpp          # takes commands for and runs the differential-drive
    │   │   ├── process_images.cpp     # searches for the white ball and requests drive_bot.cpp for a service to drive the robot 
    │   ├── srv                        # service folder for ROS services
    │   │   ├── DriveToTarget.srv
    │   ├── CMakeLists.txt             # compiler instructions
    │   ├── package.xml                # package info                  
    └── media                          # screenshots of the world and the robot

## Media 

Link to the video showing the robot chasing a white ball (preview is low quality) : https://waynestateprod-my.sharepoint.com/:v:/g/personal/hg2963_wayne_edu/EXnVLvYWrnBHnOaJXIqBslgBdzs0opuONdPs-znWKjQP1Q?e=wYTMsd
