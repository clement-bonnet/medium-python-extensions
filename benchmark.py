import time
from primelib import python as py
from primelib import cpp

# n = 11
# print("py.is_prime({}) = {}".format(n, py.is_prime(n)))
# print("cpp.is_prime({}) = {}".format(n, cpp.is_prime(n)))


COUNT = 300
if __name__ == "__main__":
    print("Running benchmarks with COUNT = {}".format(COUNT))
    print("\nPython implementation of is_prime...")
    t0 = time.perf_counter()
    for _ in range(COUNT):
        py.is_prime(100000000003)
    print("Execution time: {:3f}".format(time.perf_counter() - t0))
    print("\nC++ implementation of is_prime...")
    t0 = time.perf_counter()
    for _ in range(COUNT):
        cpp.is_prime(100000000003)
    print("Execution time: {:3f}".format(time.perf_counter() - t0))