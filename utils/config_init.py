# One file contains short reference names. 
# The second file contains the links themselves. 
#
# It connects them by type:
# short_link_name - space - link
#
# This is the format LastTrench reads link bases in.

# short_link_file = file1.txt
# link_file = file2.txt
#
# save result on file3.txt

what1 = input("Enter link_file: ")
what = input("Enter domain_file: ")

with open(what, 'r') as what, open(what1, 'r') as what1:
    lines1 = what.readlines()
    lines2 = what1.readlines()

merged_string = ''.join([line1.rstrip() + ' ' + line2.rstrip() + '\n' for line1, line2 in zip(lines1, lines2)])

with open("result.txt", 'w') as file3:
    file3.write(merged_string)
    print("Check result.txt")

