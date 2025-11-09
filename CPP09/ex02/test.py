import subprocess
import itertools

for i in range(20):
    for p in list(itertools.permutations(range(i + 2))):
        process = subprocess.Popen(["./PmergeMe"] + [str(ip) for ip in p])
        process.wait()
        if (process.returncode != 0):
            print(" ".join([str(ip) for ip in p]))
            print("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
            