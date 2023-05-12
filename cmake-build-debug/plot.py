from matplotlib import pyplot as plt

if __name__ == "__main__":

    plt.figure(1)
    n_arr = []
    value_arr = []
    with open('neighborhood.txt') as data:
        for line in data:
            row = line.split()
            if row:
                value_arr.append(float(row[1]))
                n_arr.append(int(row[0]))
    print(n_arr)
    n = int (len(n_arr) / 3)
    print(n)
    plt.title("Result vs. Sample size")
    plt.xlabel("n")
    plt.ylabel("result")
    plt.plot(n_arr[0:n-1], value_arr[0:n-1], label="Adjacent Interchange")
    plt.plot(n_arr[n:2*n-1], value_arr[n:2*n-1], label="Insert")
    plt.plot(n_arr[2*n:3*n-1], value_arr[2*n:3*n-1], label="Swap")
    plt.legend()

    plt.figure(2)
    iter_arr = []
    v_arr = []
    duration_arr = []
    with open('iteration.txt') as data:
        for line in data:
            row = line.split()
            if row:
                v_arr.append(float(row[1]))
                iter_arr.append(int(row[0]))
                duration_arr.append(float(row[2]))
    plt.title("Result vs. Number of iterations")
    plt.xlabel("number of iterations")
    plt.ylabel("result")
    plt.plot(iter_arr, v_arr)

    plt.figure(3)
    plt.title("Time vs. Number of iterations")
    plt.xlabel("number of iterations")
    plt.ylabel("time")
    plt.plot(iter_arr, duration_arr)

    plt.figure(4)
    div_arr =[]
    for i in range (0, len(iter_arr)):
        div_arr.append(v_arr[i] / duration_arr[i])

    plt.title("Result / Time vs. Number of iterations")
    plt.xlabel("number of iterations")
    plt.ylabel("result / time")
    plt.plot(iter_arr[0:17], div_arr[0:17])

    plt.figure(5)
    iter_arr = []
    v_arr = []
    duration_arr = []
    with open('iterationVersion2.txt') as data:
        for line in data:
            row = line.split()
            if row:
                v_arr.append(float(row[1]))
                iter_arr.append(int(row[0]))
                duration_arr.append(float(row[2]))
    plt.title("Result vs. Iteration method")
    plt.xlabel("number of iterations")
    plt.ylabel("result")
    plt.plot(iter_arr, v_arr, label="Maximum number of iterations = 250 000")
    plt.plot(iter_arr, duration_arr, label="Maximum stagnation = 10")
    plt.legend()


    plt.show()