import os
import sys
from glob import glob

TEMP_FILE = 'output.txt'
MAIN_PROGRAM = 'compiled_file.exe'
FOLDER = '.\\Questoes\\'
C = platform_commands()

def main():
	print("Platform: ", sys.platform)
	test_results = []
	if len(sys.argv) == 1:
		subfolders = glob(FOLDER + "*/")
		print("Folders to test:", *subfolders, sep='\n')
		for subfolder in subfolders:
			test_results += do_its_thing(subfolder)
	else:
		test_results += do_its_thing(sys.argv[1])

	for test in test_results:
		if not test["pass"]:
			sys.exit("Failed one or more tests.")
	sys.exit(0)

def do_its_thing(folder):
	print(folder.split("\\")[-2])
	
	
	cmd = f'gcc -std=c99 \
	-Wextra -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings -Wlogical-op -Wredundant-decls -Wshadow \
	-o {folder+MAIN_PROGRAM} {folder}solution.c'
	
	compiled = not os.system(cmd)

	# test_folders = ["./"]
	if not compiled:
		sys.exit("Didn't compile")

	tests = get_tests(folder)
	run_tests(tests, folder)
	
	os.system(f"{C['rm']} {folder}{MAIN_PROGRAM}")
	os.system(f"{C['rm']} {TEMP_FILE}")

	return tests


def platform_commands():
	if 'win' in (pf := sys.platform.lower()):
		c = {'rm': 'del'}
	else:
		if "linux" not in pf:
			print("Undefined behavior in this platform")
		c = {'rm': 'rm'}

	return c

def get_tests(folder):
	input_files = glob(folder + "*.in")
	output_files = glob(folder + "*.out")

	tests = []

	# The "[:]" is so we're iterating over a copy of the list, so we can delete items in
	# it and still iterate properly.
	for file in input_files[:]:
		if (output := file.replace(".in", ".out")) in output_files:
			tests.append(
				{
				'input_path': input_files.pop(input_files.index(file)),
				'expected_path': output,
				'expected': None,
				'actual': None,
				'pass': None # Possibilities: 
				}
			)

			output_files.remove(output)


	if input_files or output_files:
		print(
			"These files don't have a matching test and will be ignored:",
			*input_files,
			*output_files, 
			sep='\n'
		)

	if not tests:
		sys.exit("No valid tests to run.")

	return tests

def run_tests(tests, folder):
	for test_number, test in enumerate(tests):
		# print(test)
		cmd = f"{folder}{MAIN_PROGRAM} < {test['input_path']} > {TEMP_FILE}"
		# print(cmd)
		if os.system(cmd):
			test['pass'] = True
			with open(TEMP_FILE) as f:
				test['actual'] = "Runtime error.\n" + f.read()
			print(" TEST", test_number + 1,"DIDN'T PASS \n", test['actual'])
			continue

		with open(test['expected_path']) as file:
			test['expected'] = [line.strip(" \n") for line in file.read().strip(" \n").split("\n")]
		
		with open(TEMP_FILE) as file:
			test['actual'] = [line.strip(" \n") for line in file.read().strip(" \n").split("\n")]
		
		for _ in range(test['expected'].count('')):
			test['expected'].remove('')
		for _ in range(test['actual'].count('')):
			test['actual'].remove('')

		test['expected'] = '\n'.join(test['expected'])
		test['actual'] = '\n'.join(test['actual'])
		test['pass'] = True if (correct := test['expected'] == test['actual']) else False

		if correct:
			print(" TEST", test_number + 1,"PASSED ")
		else:
			print(" TEST", test_number + 1,"DIDN'T PASS ")
			print("Expected:\n", test['expected'])
			print("Actual:\n", test['actual'])



if __name__ == "__main__":
	main()