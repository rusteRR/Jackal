#include "settings.h"
#include <random>


jackal::SimplePointerType jackal::Settings::get_simple_pointer() {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(0, static_cast<int> (m_simple_pointer.size() - 1));
    int index = distr(eng);
    SimplePointerType type = m_simple_pointer[index].first;
    if (--m_simple_pointer[index].second == 0) {
        m_simple_pointer.erase(m_simple_pointer.begin() + index);
    }
    return type;
}

jackal::MultiPointerType jackal::Settings::get_multi_pointer() {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(0, static_cast<int> (m_multi_pointer.size() - 1));
    int index = distr(eng);
    MultiPointerType type = m_multi_pointer[index].first;
    if (--m_multi_pointer[index].second == 0) {
        m_multi_pointer.erase(m_multi_pointer.begin() + index);
    }
    return type;
}