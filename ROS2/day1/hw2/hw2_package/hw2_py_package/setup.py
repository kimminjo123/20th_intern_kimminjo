from setuptools import find_packages, setup

package_name = 'hw2_py_package'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='kmj',
    maintainer_email='kmj@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'hw2 = hw2_py_package.publisher:main',
            'hw2_2 = hw2_py_package.subscriber:main',
        ],
    },
)
