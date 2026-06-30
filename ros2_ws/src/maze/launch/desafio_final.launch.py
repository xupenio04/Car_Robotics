import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    maze_share = get_package_share_directory('maze')
    ydlidar_share = get_package_share_directory('ydlidar_ros2_driver')

    params_file = LaunchConfiguration('params_file')
    navegador_params = os.path.join(maze_share, 'config', 'navegador_params.yaml')
    lidar_params = os.path.join(ydlidar_share, 'params', 'G2.yaml')

    return LaunchDescription([
        DeclareLaunchArgument(
            'params_file',
            default_value=lidar_params,
            description='Arquivo de parâmetros do YDLidar G2',
        ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(ydlidar_share, 'launch', 'ydlidar_launch.py'),
            ),
            launch_arguments={'params_file': params_file}.items(),
        ),

        Node(
            package='controlador_base',
            executable='controlador_base',
            name='controlador_base',
            output='screen',
        ),

        Node(
            package='controlador_servo',
            executable='controlador_servo_node',
            name='controlador_servo',
            output='screen',
        ),

        Node(
            package='camera_pkg',
            executable='camera_service',
            name='camera_service',
            output='screen',
        ),

        Node(
            package='maze',
            executable='navegador',
            name='navegador',
            output='screen',
            parameters=[navegador_params],
        ),
    ])
