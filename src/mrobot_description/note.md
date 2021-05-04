## URDF
* urdf_to_graphiz mrobot_chassis.urdf\
查看URDF整体结构

* check_urdf mrobot_chassis.urdf\
解析URDF文件并发现错误
```xml
<robot> 包含name属性

<link name="base_link"> 连杆的属性
    <visual> 定义外观属性
        <origin xyz=" 0 0 0" rpy="0 0 0" /> 定义起点坐标
        <geometry> 定义几何性质
            <cylinder length="0.005" radius="0.13"/>
                包含length长度属性
                包含radius半径属性
        </geometry>
        <material name="yellow"> 定义材料颜色
            <color rgba="1 0.4 0 1"/>
        </material>
    </visual>
    <inertial> ... </inertial> 物理惯性属性
    <collision> ... </collision> 碰撞属性
</link>

<joint name="base_left_motor_joint" type="fixed"> type属性定义了关节类型
    <origin xyz="-0.055 0.075 0" rpy="0 0 0" />
    <parent link="base_link"/> 上一个link
    <child link="left_motor" /> 下一个link
    <calibration .../> 关节的位置参考，用于校准绝对位置
    <dynamics damping .../> 描述物理属性，阻尼比什么的
    <limit effort .../> 描述极限值，关节上下位限制什么的
    ...
</joint>

<gazebo reference="link_1"> 仿真用的标签
    <material>Gazebo/Black</material>
</gazebo>
 ```
![joint_para](joint_para.png)

在mrobot_chassis.urdf中看具体的应用\
跑launch文件

![frame_urdf](frame_urdf.png)

joint_state_publisher是用于调整节点状态的ui，可以控制轮子的转动（除了fixed固定的joint）\

接下来添加碰撞和惯性属性\

