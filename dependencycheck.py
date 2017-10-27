import sys

projects = map(str,raw_input().strip().split(','))

dependencies = map(str,raw_input().strip().split(', ('))

# remove the starting words
projects[0] = projects[0][-1]
projects = [x[-1] for x in projects]
dependencies[0] =dependencies[0][-5:] 

# convert to tuples
dependencies = [(x[0],x[-2]) for x in dependencies]

print projects
print dependencies

depends_on_dict = {}


for key in dependencies:
	if key[1] in depends_on_dict:
		depends_on_dict[key[1]].append(key[0])
	else:
		depends_on_dict[key[1]] = [key[0]]



print depends_on_dict

# build the allows for dictionary
allows_for_dict = {}


for key in dependencies:
	if key[0] in allows_for_dict:
		allows_for_dict[key[0]].append(key[1])
	else:
		allows_for_dict[key[0]] = [key[1]]

print allows_for_dict

"""
now we look for any projects that have 0 dependencies and then account for the
newly built projects and repeat the process until all projects are accounted for
or no new projects can be completed
"""
independent = [ x for x in projects if x not in depends_on_dict.keys()]
changed = True
print independent

recent = independent

while(changed):
	changed = False
	# see if any of the newly independent projects had projects that were dependent
	# on them
	to_change = []
	for key in recent:
		if key in allows_for_dict:
			to_change += allows_for_dict[key]

	print to_change


	# remove the independent programs from dependencies
	#
	recent = []
	for value in to_change:
		if value in depends_on_dict:
			print depends_on_dict[value]
			depends_on_dict[value] = [x for x in depends_on_dict[value] if x not in independent]
			print depends_on_dict[value]
			if len(depends_on_dict[value]) == 0:
				independent.append(value)
				recent.append(value)
				depends_on_dict.pop(value, None)
				changed = True

	
print independent