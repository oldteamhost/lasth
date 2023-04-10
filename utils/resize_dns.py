# Opens a file with short link names and brings them to 14 characters, no more no less.
# Fills the void with stars.

input_file = input("Enter base_file: ")

def process_file(file_name):
    with open(file_name, 'r') as f:
        lines = f.readlines()
        processed_lines = []
        for line in lines:
            words = line.split()
            if len(words) > 0:
                first_word = words[0]
                if len(first_word) < 14:
                    first_word = first_word.ljust(14, '*')
                elif len(first_word) > 14:
                    first_word = first_word[:14]
                processed_lines.append(first_word + ' ' + ' '.join(words[1:]).replace(' ', '*'))

    return processed_lines

processed_lines = process_file(input_file)

with open(input_file, 'w') as f:
    for line in processed_lines:
        f.write(line + '\n')

print("Results saved to {}".format(input_file))

