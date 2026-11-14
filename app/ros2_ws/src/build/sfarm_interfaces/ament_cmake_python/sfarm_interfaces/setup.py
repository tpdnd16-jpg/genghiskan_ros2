from setuptools import find_packages
from setuptools import setup

setup(
    name='sfarm_interfaces',
    version='0.0.1',
    packages=find_packages(
        include=('sfarm_interfaces', 'sfarm_interfaces.*')),
)
