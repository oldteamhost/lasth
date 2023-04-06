# Opens file2.txt with links like: https://dns/
# It cuts the dns from them and displays the result.

import re

input_file = input("Enter file_link: ")
output_file = input("Enter output_file: ");

with open(input_file, 'r') as f:
    links = f.readlines()

domains = []
for link in links:
    match = re.search(r'https?://([^/]+)', link)
    if match:
        domains.append(match.group(1))
    else:
        print(f'No match found for link: {link.strip()}')
with open(output_file, 'w') as output_file:
    output_file.write('\n'.join(domains))

print("Results saved to {}".format(output_file))
