
class Caesar {
	public:

		static const unsigned am_letter_count = 26;
        
		Caesar(){};
		Caesar(const std::string& new_sourse_text, const size_t& new_key);
		~Caesar(){};

		void setSourse_text(const std::string& new_sourse_text);
		std::string getSourse_text();

		void setKey(const size_t& new_key);
		size_t getKey();

		void encrypt(const std::string&, size_t);
		void decrypt(const std::string&, size_t);	
		
	private:
		std:: string sourse_text;
		size_t key;
};

