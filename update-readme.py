import os
import glob

repo_url = 'https://github.com/JayMody/LeetCode/blob/master'

with open('base_readme.txt', 'r') as fi:
    text = fi.read()

code = [('python', '.py'), ('c++', '.cpp'), ('java', '.java')]

files = []
for directory, extension in code:
    files.extend(glob.glob(os.path.join(directory, '*' + extension)))

problems = {}
for file in files:
    with open(file, 'r') as fi:
        lines = []
        for l in range(8):
            lines.append(fi.readline())
        lines = [line[2:].strip() for line in lines]
        
        num, name, url, lang, diff, o_time, o_space, tags = tuple(lines)

        if num not in problems.keys():
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

for entry in problems.values():
    text += ' | '.join(entry) + '\n'

with open('README.md', 'w') as fo:
    fo.write(text)