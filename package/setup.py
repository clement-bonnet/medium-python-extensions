
import setuptools

with open("README.md", "r") as f:
    long_description = f.read()

cpp_module = setuptools.Extension("primelib.cpp", sources = ["cpp/cppmodule.cpp"])

setuptools.setup(
    name="primelib-clement-bonnet", # Replace with your own username
    version="0.0.1",
    author="Clément Bonnet",
    author_email="clement.bonnet16@gmail.com",
    description="A small package to work with prime numbers, written in several languages",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/clement-bonnet/medium-python-extensions",
    ext_modules = [cpp_module],
    packages=["primelib"],
    # packages=setuptools.find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ]
)