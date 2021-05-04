**gazebo.launch**

```
$ roslaunch urdf_sim_tutorial 09-joints.launch
$ rostopic echo /joint_states
---
header: 
  seq: 3578
  stamp: 
    secs: 71
    nsecs: 941000000
  frame_id: ''
name: []
position: []
velocity: []
effort: []
---
header: 
  seq: 3579
  stamp: 
    secs: 71
    nsecs: 961000000
  frame_id: ''
name: []
position: []
velocity: []
effort: []
---
```

```
$ roslaunch urdf_sim_tutorial 09-joints.launch model:=urdf/10-firsttransmission.urdf.xacro
$ rostopic echo /joint_states
---
header: 
  seq: 1034
  stamp: 
    secs: 21
    nsecs:  36000000
  frame_id: ''
name: 
  - head_swivel
position: [-1.1104268615724777e-08]
velocity: [-2.2493156425981709e-13]
effort: [0.0]
---
^Cheader: 
  seq: 1035
  stamp: 
    secs: 21
    nsecs:  56000000
  frame_id: ''
name: 
  - head_swivel
position: [-1.3681548338695393e-08]
velocity: [-4.543452255807538e-09]
effort: [0.0]
---
```

```
$ rostopic pub /r2d2ead_controller/command std_msgs/Float64 "data: -0.707"
publishing and latching message. Press ctrl-C to terminate

$ rostopic echo /r2d2_head_controller/command
data: -0.707
---
```