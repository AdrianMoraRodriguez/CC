#include <vector>
#include <string>

std::vector<std::string> split(std::string str, char delimiter) {
  std::vector<std::string> result;
  for (int i = 0; i < str.size(); i++) {
    std::string word = "";
    while (str[i] != delimiter && i < str.size()) {
      word += str[i];
      i++;
    }
    result.push_back(word);
  }
  return result;
}

std::vector<std::string> getImportantLines(std::string filename) {
  std::ifstream file(filename);
  std::string line;
  std::vector<std::string> important_lines;
  while (std::getline(file, line)) {
    if (line[0] != '#') {
      important_lines.push_back(line);
    }
  }
  return important_lines;
}