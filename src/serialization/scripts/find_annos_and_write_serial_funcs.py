SEARCH_DIR = "src/"
SEARCH_EXTS = [".h", ".cpp", ".ixx", ".hpp", ".c", ".cc"]
SEARCH_ANNOTATION = "/// @HAWSOO_SERIALIZE."
IGNORE_DIRS = ["serialization/"]


import os


# Searches directory structure starting from `SEARCH_DIR` to find all files that could get compiled
# for flagging for search/review later.
def find_files_to_search():
    found_files = []

    for root, dirs, files in os.walk(SEARCH_DIR):
        for file in files:
            _, file_ext = os.path.splitext(file)
            if file_ext in SEARCH_EXTS:
                # Successfully found the right file!
                found_files.append(os.path.join(root, file))

    return found_files


# Finds occurrances of `SEARCH_ANNOTATION` within file `fname`.
def find_all_annotations(fname: str):
    occurrances = []

    with open(fname, "r") as f:
        line_idx = 1
        for line in f:
            if line.strip() == SEARCH_ANNOTATION:
                # Found occurrance!
                occurrances.append(line_idx)
            line_idx += 1

    return occurrances


if __name__ == '__main__':
    fnames = find_files_to_search()
    for fname in fnames:
        anno_occurs = find_all_annotations(fname)

        # @DEBUG
        for asdfasdf in anno_occurs:
            print(f'{fname}:{asdfasdf}')
    
    pass
