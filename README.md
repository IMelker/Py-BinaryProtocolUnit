# Py-BinaryProtocolUnit
Wrapper for `std::map<std::string, std::string>`  with serialisation to binary. Shared library to python using `ctypes`.

# Instalation
First of all you need to compile cpp shared lib, that provides wrapper.

`cd ./libbpu`

`make`

`make install`

Now you can run example scripts and work with lib using `pybpu.py`.

# Example run
`cd ../`

`python example.py`
