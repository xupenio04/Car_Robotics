from setuptools import find_packages
from setuptools import setup

setup(
    name='controlador_servo',
    version='0.0.0',
    packages=find_packages(
        include=('controlador_servo', 'controlador_servo.*')),
)
