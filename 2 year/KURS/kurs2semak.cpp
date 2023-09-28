#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <Windows.h>
#include <algorithm>
#include <ctime>
#include <limits>
#include <cctype>
#include <vector>
using namespace std;

const int TABLE_SIZE = 100;

struct Reader {
	string ticketType;
	string ticket;
	int ticketNumber;
	int registrationYear;
	string name;
	int year;
	string address;
	string workplace;
};

struct Book {
	string bookCode;
	string author;
	string bookname;
	string company;
	int year;
	int full;
	int current;
	int sectionNumber;
	int bookNumber;
};
struct TreeNode {
	Book book;
	int height;
	TreeNode* left;
	TreeNode* right;
	TreeNode(Book book) : book(book), height(1), left(nullptr), right(nullptr) {}
};

string getCurrentDate() {
	time_t now = time(nullptr);
	tm local_time;
	localtime_s(&local_time, &now);
	char buffer[11];
	strftime(buffer, 11, "%d.%m.%Y", &local_time);
	return buffer;
}
string getNextDate() {
	time_t now = time(nullptr);
	tm local_time;
	localtime_s(&local_time, &now);

	// Добавляем 14 дней к текущей дате
	const int secondsPerDay = 24 * 60 * 60;
	now += 14 * secondsPerDay;
	localtime_s(&local_time, &now);

	char buffer[11];
	strftime(buffer, 11, "%d.%m.%Y", &local_time);
	return buffer;
}
class Issue {
public:
	string ticketNumber; // Номер билета читателя
	string bookCode; // Шифр книги
	string issueDate; // Дата выдачи
	string returnDate; // Дата возврата

	Issue(const string& tn, const string& bc, const string& id, const string& rd)
		: ticketNumber(tn), bookCode(bc), issueDate(id), returnDate(rd) {}

	string getTicketNumber() const {
		return ticketNumber;
	}

	string getBookCode() const {
		return bookCode;
	}

	string getIssueDate() const {
		return issueDate;
	}

	string getReturnDate() const {
		return returnDate;
	}
};
struct Node {
	Issue issue;
	Node* prev;
	Node* next;

	Node(const Issue& i) : issue(i), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:

	Node* head;
	int size;
	Node* tail;

public:
	DoublyLinkedList() : head(nullptr), size(0), tail(nullptr) {}

	~DoublyLinkedList() {
		clear();
	}
	Node* getHead() const {
		return head;
	}
	void addBack(const Issue& issue) {
		Node* newNode = new Node(issue);
		if (size == 0) {
			head = newNode;
			tail = newNode;
			newNode->prev = newNode;
			newNode->next = newNode;
		}
		else {
			newNode->prev = tail;
			newNode->next = head;
			tail->next = newNode;
			head->prev = newNode;
			tail = newNode;
		}
		size++;
	}
	int getSize() const {
		return size;
	}

	vector<Node*> findReadersByBookCode(const string& bookCode) {
		std::vector<Node*> readers;

		Node* current = head;
		for (int i = 0; i < size; i++) {
			if (current->issue.getBookCode() == bookCode) {
				readers.push_back(current);
			}
			current = current->next;
		}

		return readers;
	}

	void shakerSortByFirstDigit(DoublyLinkedList& list) {
		if (list.size <= 1) {
			return;
		}

		bool swapped = true;
		int start = 0;
		int end = list.size - 1;

		while (swapped) {
			swapped = false;

			// Проход слева направо
			Node* current = list.head;
			for (int i = start; i < end; i++) {
				int currentCode = current->issue.getBookCode()[0] - '0';
				int nextCode = current->next->issue.getBookCode()[0] - '0';

				if (currentCode > nextCode) {
					// Обмен значениями
					swap(current->issue, current->next->issue);
					swapped = true;
				}

				current = current->next;
			}

			if (!swapped) {
				break;
			}

			// Уменьшаем диапазон
			end--;

			// Проход справа налево
			current = list.tail;
			for (int i = end; i > start; i--) {
				int currentCode = current->issue.getBookCode()[0] - '0';
				int prevCode = current->prev->issue.getBookCode()[0] - '0';

				if (currentCode < prevCode) {
					// Обмен значениями
					swap(current->issue, current->prev->issue);
					swapped = true;
				}

				current = current->prev;
			}

			// Увеличиваем диапазон
			start++;
		}
	}

	void remove(Node* node) {
		if (size == 0 || node == nullptr) {
			return;
		}

		if (size == 1) {
			delete node;
			head = nullptr;
			tail = nullptr;
		}
		else {
			node->prev->next = node->next;
			node->next->prev = node->prev;
			if (node == head) {
				head = node->next;
			}
			if (node == tail) {
				tail = node->prev;
			}
			delete node;
		}
		size--;
	}

	void clear() {
		Node* current = head;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void printList() {
		if (size == 0) {
			cout << "Список пуст" << endl;
			return;
		}
		Node* current = head;
		for (int i = 0; i < size; i++) {
			cout << "Номер билета: " << current->issue.getTicketNumber()
				<< ", шифр книги: " << current->issue.getBookCode()
				<< ", дата выдачи: " << current->issue.getIssueDate()
				<< ", дата возврата: " << current->issue.getReturnDate() << endl;
			current = current->next;
		}
	}

};



class AVLTree {
private:
	TreeNode* root;

	int height(TreeNode* node) {
		if (node == nullptr) {
			return 0;
		}
		return node->height;
	}

	int balanceFactor(TreeNode* node) {
		if (node == nullptr) {
			return 0;
		}
		return height(node->right) - height(node->left);
	}

	void fixHeight(TreeNode* node) {
		int leftHeight = height(node->left);
		int rightHeight = height(node->right);
		node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
	}
	TreeNode* findMin(TreeNode* node) {
		if (node->left == nullptr) {
			return node;
		}
		return findMin(node->left);
	}
	TreeNode* rotateRight(TreeNode* p) {
		TreeNode* q = p->left;
		p->left = q->right;
		q->right = p;
		fixHeight(p);
		fixHeight(q);
		return q;
	}

	TreeNode* rotateLeft(TreeNode* q) {
		TreeNode* p = q->right;
		q->right = p->left;
		p->left = q;
		fixHeight(q);
		fixHeight(p);
		return p;
	}

	TreeNode* balance(TreeNode* p) {
		fixHeight(p);
		if (balanceFactor(p) == 2) {
			if (balanceFactor(p->right) < 0) {
				p->right = rotateRight(p->right);
			}
			return rotateLeft(p);
		}
		if (balanceFactor(p) == -2) {
			if (balanceFactor(p->left) > 0) {
				p->left = rotateLeft(p->left);
			}
			return rotateRight(p);
		}
		return p;
	}

	TreeNode* insertHelper(TreeNode* node, Book book) {
		if (node == nullptr) {
			return new TreeNode(book);
		}
		if (book.bookCode < node->book.bookCode) {
			node->left = insertHelper(node->left, book);
		}
		else {
			node->right = insertHelper(node->right, book);
		}
		return balance(node);
	}

	void printHelper(TreeNode* node) {
		if (node != nullptr) {
			printHelper(node->left);
			cout << node->book.bookCode << " " << node->book.author << " " << node->book.bookname << " " << node->book.company << " " << node->book.year << " " << node->book.full << " " << node->book.current << endl;
			printHelper(node->right);
		}
	}
	TreeNode* deleteHelper(TreeNode* node, string bookCode) {
		if (node == nullptr) {
			return nullptr;
		}
		if (bookCode < node->book.bookCode) {
			node->left = deleteHelper(node->left, bookCode);
		}
		else if (bookCode > node->book.bookCode) {
			node->right = deleteHelper(node->right, bookCode);
		}
		else {
			if (node->left == nullptr && node->right == nullptr) {
				delete node;
				node = nullptr;
			}
			else if (node->left == nullptr) {
				TreeNode* temp = node;
				node = node->right;
				delete temp;
			}
			else if (node->right == nullptr) {
				TreeNode* temp = node;
				node = node->left;
				delete temp;
			}
			else {
				TreeNode* temp = findMin(node->right);
				node->book = temp->book;
				node->right = deleteHelper(node->right, temp->book.bookCode);
			}
		}
		if (node == nullptr) {
			return nullptr;
		}
		return balance(node);
	}
	bool BMContains(const string& text, const string& pattern) {
		int textLen = text.length();
		int patternLen = pattern.length();

		if (patternLen == 0)
			return true;

		// Создание таблицы сдвигов
		const int tableSize = 256; // Размер таблицы сдвигов (ASCII-символы)
		int shiftTable[tableSize];
		for (int i = 0; i < tableSize; i++) {
			shiftTable[i] = patternLen; // Инициализация сдвигов значениями длины образца
		}
		for (int i = 0; i < patternLen - 1; i++) {
			shiftTable[pattern[i]] = patternLen - 1 - i;
		}

		int i = patternLen - 1; // Индекс текущего символа в тексте

		while (i < textLen) {
			int j = patternLen - 1; // Индекс текущего символа в образце

			// Поиск с конца образца до начала
			while (j >= 0 && i >= 0 && i < textLen && text[i] == pattern[j]) {
				i--;
				j--;
			}

			if (j == -1) {
				return true; // Образец найден
			}

			// Применение правила сдвига и правила хорошего суффикса
			int shift = shiftTable[text[i]];
			i += shift;
		}

		return false; // Совпадение не найдено
	}



	TreeNode* searchHelper(TreeNode* node, string bookCode) {
		if (node == nullptr || node->book.bookCode == bookCode) {
			return node;
		}
		if (bookCode < node->book.bookCode) {
			return searchHelper(node->left, bookCode);
		}
		return searchHelper(node->right, bookCode);
	}
	void searchByFragmentHelper(TreeNode* node, const string& fragment, vector<Book*>& foundBooks) {
		if (node == nullptr) {
			return;
		}

		searchByFragmentHelper(node->left, fragment, foundBooks);

		// Поиск фрагмента в названии книги
		if (!node->book.bookname.empty() && node->book.bookname.find(fragment) != string::npos) {
			foundBooks.push_back(&node->book);
		}

		// Поиск фрагмента в ФИО автора
		if (!node->book.author.empty() && node->book.author.find(fragment) != string::npos) {
			foundBooks.push_back(&node->book);
		}

		searchByFragmentHelper(node->right, fragment, foundBooks);
	}


public:
	AVLTree() : root(nullptr) {}

	void insert(Book book) {
		root = insertHelper(root, book);
	}
	void deleteBook(AVLTree& avl, string bookCode) {
		avl.root = deleteHelper(avl.root, bookCode);
	}
	void print() {
		printHelper(root);
	}
	Book* search(string bookCode) {
		TreeNode* result = searchHelper(root, bookCode);
		if (result == nullptr) {
			return nullptr;
		}
		return &result->book;
	}
	void searchByFragment(const string& fragment) {
		vector<Book*> foundBooks;
		searchByFragmentHelper(root, fragment, foundBooks);

		if (!foundBooks.empty()) {
			cout << "Результаты поиска:" << endl;
			for (Book* book : foundBooks) {
				cout << "Шифр книги: " << book->bookCode << endl;
				cout << "Автор(ы): " << book->author << endl;
				cout << "Название: " << book->bookname << endl;
				cout << "Издательство: " << book->company << endl;
				cout << "Год издания: " << book->year << endl;
				cout << "Количество экземпляров в наличии: " << book->current << endl;
				cout << "-------------------------" << endl;
			}
		}
		else {
			cout << "По вашему запросу ничего не найдено." << endl;
		}
	}
};
class ReaderHashTable {
private:
	Reader* table[TABLE_SIZE] = { nullptr };

	int hash(int key) {
		return key % TABLE_SIZE;
	}

public:
	Reader** getTable() {
		return table;
	}

	void addReader(Reader reader) {
		int key = reader.ticketNumber;
		int index = hash(key);

		while (table[index] != nullptr) {
			index = (index + 1) % TABLE_SIZE;
		}

		table[index] = new Reader(reader);
	}

	Reader* findReader(int key) {
		int index = hash(key);

		while (table[index] != nullptr && table[index]->ticketNumber != key) {
			index = (index + 1) % TABLE_SIZE;
		}

		return table[index];
	}

	void removeReader(int key) {
		int index = hash(key);

		while (table[index] != nullptr && table[index]->ticketNumber != key) {
			index = (index + 1) % TABLE_SIZE;
		}

		if (table[index] != nullptr) {
			delete table[index];
			table[index] = nullptr;
		}
	}
};

Reader readReaderData()
{
	Reader reader;

	// Считываем номер читательского билета
	cout << "Введите тип читательского билета (A, Ч или В), номер регистрации и год регистрации в формате A1234-YY: ";
	//cin >> reader.ticketType >> reader.ticketNumber >> reader.registrationYear;
	cin >> reader.ticket;
	int new_pos = reader.ticket.find('-');
	string number_str = reader.ticket.substr(1, new_pos - 1);
	reader.ticketNumber = stoi(number_str);
	string year_str = reader.ticket.substr(new_pos + 1);
	reader.registrationYear = stoi(year_str);
	reader.ticketType = reader.ticket.substr(0, 1);

	// Считываем ФИО
	cout << "Введите ФИО: ";
	cin.ignore();
	getline(cin, reader.name);
	reader.name = reader.name.substr(0, 50);

	// Считываем год рождения
	cout << "Введите год рождения: ";
	cin >> reader.year;
	while (cin.fail() || to_string(reader.year).length() > 4) {
		cout << "Ошибка ввода. Введите год рождения (не более 4 цифр): ";
		cin.clear();
		cin >> reader.year;
	}
	cin.ignore();
	// Считываем адрес
	cout << "Введите адрес: ";
	getline(cin, reader.address);

	// Считываем место работы/учебы
	cout << "Введите место работы/учебы: ";
	getline(cin, reader.workplace);

	return reader;

}

Book readBookData()
{
	Book book;
	cout << "Введите шифр книги в формате NNN.MMM: ";
	cin >> book.bookCode;
	cout << "Введите автора книги: ";
	cin.ignore();
	getline(cin, book.author);
	cout << "Введите название книги: ";
	getline(cin, book.bookname);
	cout << "Введите издательство книги: ";
	getline(cin, book.company);
	cout << "Введите год издания книги: ";
	cin >> book.year;
	cout << "Введите количество экземпляров всего: ";
	cin >> book.full;
	cout << "Введите количество экземпляров в наличии: ";
	cin >> book.current;
	return book;
}
void addBook(AVLTree& avl)
{
	Book book = readBookData();
	avl.insert(book);
}

void loadReadersFromFile(ReaderHashTable& readerHashTable, const string& filename) {
	ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		cerr << "Failed to open file: " << filename << endl;
		return;
	}

	string line;
	while (getline(inputFile, line)) {
		stringstream ss(line);
		string ticketType, ticket, name, year, address, workplace;
		getline(ss, ticket, '|');
		getline(ss, name, '|');
		getline(ss, year, '|');
		getline(ss, address, '|');
		getline(ss, workplace, '|');
		int new_pos = ticket.find('-');
		int iyear = stoi(year);
		string number_str = ticket.substr(1, new_pos - 1);
		int number = stoi(number_str);
		int reg_year = stoi(ticket.substr(new_pos + 1));
		ticketType = ticket.substr(0, 1);
		Reader reader = { ticketType, ticket, number, reg_year, name, iyear, address, workplace };
		readerHashTable.addReader(reader);
	}

	inputFile.close();
}

void loadBooksFromFile(AVLTree& avl, const string& filename)
{
	ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		cerr << "Failed to open file: " << filename << endl;
		return;
	}
	string line;
	while (getline(inputFile, line)) {
		stringstream ss(line);
		string bookCode, author, bookname, company, year, full, current;
		getline(ss, bookCode, '|');
		getline(ss, author, '|');
		getline(ss, bookname, '|');
		getline(ss, company, '|');
		getline(ss, year, '|');
		getline(ss, full, '|');
		getline(ss, current, '|');
		int iyear = stoi(year);
		int ifull = stoi(full);
		int icurrent = stoi(current);
		Book book = { bookCode, author, bookname, company, iyear, ifull, icurrent };
		avl.insert(book);
	}
}

int input_validation(int a, int b)
{
	int x;
	while (true)
	{
		while (!(cin >> x))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Неверный ввод. Повторите." << endl;
		}
		if ((x < a) || (x > b))
		{
			cout << "Неверный ввод. Повторите." << endl;
		}
		else
		{
			break;
		}
	}
	return x;

}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ReaderHashTable readerHashTable;
	AVLTree avl;
	DoublyLinkedList issueList;
	int menu = -111;
	while (menu != 0)
	{
		cout << endl <<
			"1 - Добавить читателя" << endl <<
			"2 - Поиск по номеру читательского билета" << endl <<
			"3 - Удалить читательский билет по номеру" << endl <<
			"4 - Просмотр всех зарегистрированных читателей" << endl <<
			"5 - Добавить книгу" << endl <<
			"6 - Просмотр всех имеющихся книг" << endl <<
			"7 - Удаление книги по шифру" << endl <<
			"8 - Выдача книги читателю" << endl <<
			"9 - Возврат книги от читателя" << endl <<
			"10 - Просмотр всех выданных книг" << endl <<
			"11 - Поиск книги по шифру" << endl <<
			"12 - Поиск книги по фрагментам ФИО авторов или названия" << endl <<
			"13 - Загрузить читателей" << endl <<
			"14 - Загрузить книги" << endl <<
			"0 - Выход\nВыберите действие: ";
		menu = input_validation(0, 14);
		switch (menu)
		{
		case 1:
		{
			readerHashTable.addReader(readReaderData());
			break;
		}
		case 2:
		{
			string ticket;
			cout << "Введите номер читательского билета: ";
			cin >> ticket;
			int new_pos = ticket.find('-');
			string number_str = ticket.substr(1, new_pos - 1);
			int number = stoi(number_str);
			Reader* reader = readerHashTable.findReader(number);
			if (reader != nullptr) {
				cout << "Тип читательского билета: " << reader->ticketType << endl;
				cout << "Номер регистрации: " << reader->ticketNumber << endl;
				cout << "Год регистрации: " << reader->registrationYear << endl;
				cout << "ФИО: " << reader->name << endl;
				cout << "Год рождения: " << reader->year << endl;
				cout << "Адрес: " << reader->address << endl;
				cout << "Место работы/учебы: " << reader->workplace << endl;
			}
			else {
				cout << "Читатель с номером билета " << ticket << " не найден." << endl;
			}
			break;
		}
		case 3:
		{
			int k;
			cout << "Введите номер читательского билета: ";
			k = input_validation(1000, 9999);
			Reader* readerToDelete = readerHashTable.findReader(k);
			if (readerToDelete == nullptr) {
				cout << "Читательский билет с номером " << k << " не найден." << endl;
			}
			else {
				readerHashTable.removeReader(k);
				cout << "Читательский билет с номером " << k << " удален." << endl;
			}
			break;
		}
		case 4:
		{
			Reader** table = readerHashTable.getTable();
			for (int i = 0; i < TABLE_SIZE; i++) {
				if (table[i] != nullptr) {
					cout << table[i]->name << " | " << table[i]->ticketType << table[i]->ticketNumber << "-" << table[i]->registrationYear << endl;
				}
			}
			break;
		}
		case 5:
		{
			addBook(avl);
			break;
		}
		case 6:
		{
			avl.print();
			break;
		}
		case 7:
		{
			string bookCode;
			cout << "Введите шифр, для удаления книги: ";
			cin >> bookCode;
			avl.deleteBook(avl, bookCode);
			break;
		}
		case 8:
		{
			string ticket;
			string code;
			cout << "Введите номер читательского билета: ";
			cin >> ticket;
			int new_pos = ticket.find('-');
			string number_str = ticket.substr(1, new_pos - 1);
			int number = stoi(number_str);
			Reader* reader = readerHashTable.findReader(number);
			if (reader != nullptr)
			{
				cout << "Введите шифр книги, которую нужно выдать: ";
				cin >> code;
				Book* book = avl.search(code);
				if (book != nullptr)
				{
					if (book->current > 0)
					{
						book->current--;
						string currentDate = getCurrentDate();
						string returnDate = getNextDate();
						Issue issue(ticket, code, currentDate, returnDate);
						issueList.addBack(issue);
						cout << "Книга " << book->bookname << " успешно выдана читателю " << reader->name << endl;
					}
					else
					{
						cout << "Извините, книга " << book->bookname << " не доступна для выдачи. " << endl;
					}
				}
				else
				{
					cout << "Книга с шифром " << code << " не найдена." << endl;
				}
			}
			else
			{
				cout << "Читатель с номером билета " << ticket << " не найден." << endl;
			}
			break;
		}
		case 9:
		{
			string ticket;
			string code;
			cout << "Введите номер читательского билета: ";
			cin >> ticket;
			int new_pos = ticket.find('-');
			string number_str = ticket.substr(1, new_pos - 1);
			int number = stoi(number_str);
			Reader* reader = readerHashTable.findReader(number);
			if (reader != nullptr)
			{
				cout << "Введите шифр книги, которую нужно вернуть: ";
				cin >> code;
				Book* book = avl.search(code);
				if (book != nullptr)
				{
					if (book->current < book->full)
					{
						book->current++;
						Node* current = issueList.getHead();
						while (current != nullptr)
						{
							if (current->issue.getTicketNumber() == ticket && current->issue.getBookCode() == code)
							{
								issueList.remove(current);
								cout << "Книга " << book->bookname << " успешно возвращена от читателя " << reader->name << endl;
								break;
							}
							current = current->next;
						}
					}
					else
					{
						cout << "Извините, невозможно принять книгу " << book->bookname << ". Все экземпляры в наличии." << endl;
					}
				}
				else
				{
					cout << "Книга с шифром " << code << " не найдена." << endl;
				}
			}
			else
			{
				cout << "Читатель с номером билета " << ticket << " не найден." << endl;
			}
			break;
		}

		case 10:
		{
			cout << "Список выданных книг:" << endl;

			issueList.shakerSortByFirstDigit(issueList);
			issueList.printList();
			break;
		}
		case 11:
		{
			string code;
			cout << "Введите шифр книги: " << endl;
			cin >> code;
			Book* book = avl.search(code);
			if (book != nullptr)
			{
				cout << "Результаты поиска:" << endl;
				cout << "Шифр книги: " << book->bookCode << endl;
				cout << "Автор(ы): " << book->author << endl;
				cout << "Название: " << book->bookname << endl;
				cout << "Издательство: " << book->company << endl;
				cout << "Год издания: " << book->year << endl;
				cout << "Количество экземпляров в наличии: " << book->current << endl;
				vector<Node*> readers = issueList.findReadersByBookCode(code);
				if (!readers.empty()) {
					cout << "Читатели, которым выдана данная книга:" << endl;
					for (const auto& reader : readers) {
						cout << "Номер билета: " << reader->issue.getTicketNumber() << endl;
					}
				}
				break;
			}
		}
		case 12:
		{
			string fragment;
			cout << "Введите фрагмент для поиска: ";
			cin.ignore();
			getline(cin, fragment);

			avl.searchByFragment(fragment);
			break;
		}
		case 13:
		{
			loadReadersFromFile(readerHashTable, "readers.txt");
			break;
		}
		case 14:
		{
			loadBooksFromFile(avl, "books.txt");
			break;
		}
		}
	}
	return 0;
}
