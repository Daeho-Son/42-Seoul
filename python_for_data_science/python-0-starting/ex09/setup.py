from setuptools import setup, find_packages

setup(
    name='ft_package',
    version='0.0.1',
    description='PYPI tutorial package creation written by dason',
    author='dason',
    author_email='dason@student.42seoul.kr',
    url='https://profile.intra.42.fr/users/dason',
    install_requires=[],
    packages=find_packages(exclude=[]),
    keywords=['ft_package'],
    python_requires='>=3.10',
    package_data={},
    zip_safe=False,
    classifiers=[
        'Programming Language :: Python :: 3.10',
    ],
)
