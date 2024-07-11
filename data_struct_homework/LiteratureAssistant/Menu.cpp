#include "Menu.h"

Menu::Menu() {}

void Menu::displayMenu() {
	int choice;
	do {
		std::cout << "��ѧ�о�����ʹ�ò˵�:\n";
		std::cout << "1. ��Ӵ�ƥ���ģʽ��\n";
		std::cout << "2. ��һ�γ��ı�������\n";
		std::cout << "3. ��һ��TXT�ļ�������\n";
		std::cout << "4. �˳���\n";
		std::cout << "���������ѡ����ţ�: ";
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
				std::cout << "�˳���...��лʹ��...���ߣ�Τ��&�����\n";
				break;
			default:
				std::cout << "���Ϸ������룬�����³���\n";
		}
	} while (choice != 4);
}

void Menu::addPatterns() {
	int n;
	std::cout << "�����ƥ���ģʽ��������: ";
	std::cin >> n;
	std::cin.ignore();

	for (int i = 0; i < n; ++i) {
		std::string pattern;
		std::cout << "����ģʽ������ " << (i + 1) << ": ";
		std::getline(std::cin, pattern);
		automaton.insert(pattern);
	}
	automaton.finalize();
}

void Menu::searchText() {
	std::string text;
	std::cout << "����������ĳ��ı�: ";
	std::getline(std::cin, text);

	auto results = automaton.search(text);
	for (const auto &result : results) {
		std::cout << "ģʽ�� \"" << result.first << "\" �ڴ�λ���ҵ��� ";
		for (const auto &pos : result.second) {
			std::cout << pos << " ";
		}
		std::cout << "\n";
	}
}

void Menu::searchFile() {
	std::string filename;
	std::cout << "�������ļ���: ";
	std::getline(std::cin, filename);

	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "���ܴ��ļ��������³��� " << filename << "\n";
		return;
	}

	std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();

	auto results = automaton.search(text);
	for (const auto &result : results) {
		std::cout << "ģʽ�� \"" << result.first << "\" �ڴ�λ���ҵ�: ";
		for (const auto &pos : result.second) {
			std::cout << pos << " ";
		}
		std::cout << "\n";
	}
}



