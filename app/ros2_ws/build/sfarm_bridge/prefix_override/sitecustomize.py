import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/rokey/workspace/genghiskan_ros2/app/ros2_ws/install/sfarm_bridge'
