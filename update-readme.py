# Imports
import os
import glob

# Macros
repo_url = 'https://github.com/JayMody/LeetCode/blob/master'
code = [('c++', '.cpp'), ('java', '.java'), ('python', '.py')]

# Parse through code files and get fpaths
files = []
for directory, extension in code:
    files.extend(glob.glob(os.path.join(directory, '*' + extension)))

# Compile problems table
difficulties = {'easy': 0, 'medium': 0, 'hard': 0}
problems = {}
for file in files:
    with open(file, 'r') as fi:
        lines = []

        # get first 8 lines
        lines = fi.readlines()[:8]
        lines = [line[2:].strip() for line in lines]
        
        # vars
        num, name, url, lang, diff, o_time, o_space, tags = tuple(lines)
        num = int(num)

        if num not in problems.keys():
            difficulties[diff] += 1
            problems[num] = [
                num,
                f'[{name}]({url})',
                f"[{lang}]({os.path.join(repo_url, file).replace(' ', '%20')})",
                diff,
                o_time,
                o_space,
                ', '.join(tags.split())
            ]
        else:
            problems[num][2] += f", [{lang}]({os.path.join(repo_url, file).replace(' ', '%20')})"


# Open base readme
with open('base_readme.txt', 'r') as fi:
    text = fi.read()

# Add # of difficulties
text = text.format(*list(difficulties.values()))

# Append table
for entry in sorted(problems.values()):
    text += ' | '.join([str(e) for e in entry]) + '\n'

# Write to README.md
with open('README.md', 'w') as fo:
    fo.write(text)
