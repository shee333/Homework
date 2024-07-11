#include "Menu.h"

Menu::Menu() {}

void Menu::displayMenu() {
	int choice;
	do {
		std::cout << "文学研究助手使用菜单:\n";
		std::cout << "1. 添加待匹配的模式串\n";
		std::cout << "2. 在一段长文本中搜索\n";
		std::cout << "3. 在一个TXT文件中搜索\n";
		std::cout << "4. 退出：\n";
		std::cout << "请输入你的选择（序号）: ";
		std::cin >> choice;
		std::cin.ignore();

		switch (choice) {
			case 1:
				addPatterns();
				break;
			case 2:
				searchText();
				break;
			case 3:
				searchFile();
				break;
			case 4:
				std::cout << "退出中...感谢使用...作者：韦旭&李国庆\n";
				break;
			default:
				std::cout << "不合法的输入，请重新尝试\n";
		}
	} while (choice != 4);
}

void Menu::addPatterns() {
	int n;
	std::cout << "输入待匹配的模式串的数量: ";
	std::cin >> n;
	std::cin.ignore();

	for (int i = 0; i < n; ++i) {
		std::string pattern;
		std::cout << "输入模式串内容 " << (i + 1) << ": ";
		std::getline(std::cin, pattern);
		automaton.insert(pattern);
	}
	automaton.finalize();
}

void Menu::searchText() {
	std::string text;
	std::cout << "输入待搜索的长文本: ";
	std::getline(std::cin, text);

	auto results = automaton.search(text);
	for (const auto &result : results) {
		std::cout << "模式串 \"" << result.first << "\" 在此位置找到： ";
		for (const auto &pos : result.second) {
			std::cout << pos << " ";
		}
		std::cout << "\n";
	}
}

void Menu::searchFile() {
	std::string filename;
	std::cout << "请输入文件名: ";
	std::getline(std::cin, filename);

	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "不能打开文件，请重新尝试 " << filename << "\n";
		return;
	}

	std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();

	auto results = automaton.search(text);
	for (const auto &result : results) {
		std::cout << "模式串 \"" << result.first << "\" 在此位置找到: ";
		for (const auto &pos : result.second) {
			std::cout << pos << " ";
		}
		std::cout << "\n";
	}
}



