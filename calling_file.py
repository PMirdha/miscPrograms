import called_file

def func1():
	for i in range(0,4):
		print("\nIn func1 - "+str(i))
		called_file.func2()

if __name__ == "__main__":
	func1()