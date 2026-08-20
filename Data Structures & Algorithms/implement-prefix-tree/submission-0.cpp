class PrefixTree {
public:
    PrefixTree() {

    }

    void insert(std::string word) {
        auto cur = &root;
        for (auto const& c : word) {
            if (auto& child {cur->children[c - 'a']}; child.get()) {
                cur = child.get();
            }
            else {
                cur->children[c - 'a'] = std::make_unique<Node>();
                cur = cur->children[c - 'a'].get();
            }
        }
        cur->is_word = true;
    }

    bool search(std::string word) {
        auto cur = &root;
        for (auto const& c : word) {
            if (auto& child {cur->children[c - 'a']}; child.get()) {
                cur = child.get();
            }
            else {
                return false;
            }
        }
        return cur->is_word;
    }

    bool startsWith(std::string prefix) {
        auto cur = &root;
        for (auto const& c : prefix) {
            if (auto& child {cur->children[c - 'a']}; child.get()) {
                cur = child.get();
            }
            else {
                return false;
            }
        }
        return true;
    }
private:
    struct Node {
        std::array<std::unique_ptr<Node>, 26> children{};
        bool is_word{};
        char c{};
    };

    Node root{};
};