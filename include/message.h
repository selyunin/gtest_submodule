//
// Created by selyunin on 04.06.18.
//

#ifndef PROJECT1_MESSAGE_H
#define PROJECT1_MESSAGE_H

#include <iostream>

using namespace std;

enum class ErrorStatus{
    Success,
    NotEnoughData,
    InvalidData,
};

template <typename TReadIter, typename TWriteIter>
class Message {
public:
    using ReadIterator = TReadIter;
    using WriteIterator = TWriteIter;

    ErrorStatus read(ReadIterator& iter, std::size_t len){
        return readimpl(iter, len);
    }

    ErrorStatus write(WriteIterator& iter, std::size_t len){
        return writeimpl(iter, len);
    }

private:

    virtual ErrorStatus readimpl(ReadIterator& iter, std::size_t len) = 0;
    virtual ErrorStatus writeimpl(WriteIterator& iter, std::size_t len) = 0;
};

template<typename TReadIter, typename TWriteIter>
class HelloMessage : public Message<TReadIter, TWriteIter>
{

    using Base = Message<TReadIter, TWriteIter>;
public:
    using Base::ReadIterator;
    using Base::WriteIterator;
protected:
//private:
    virtual ErrorStatus readimpl(TReadIter& iter, std::size_t len) override {
        cout<<"reading hello"<<endl;
        return ErrorStatus::Success;
    }

    virtual ErrorStatus writeimpl(TWriteIter& iter, std::size_t len) override {
        return ErrorStatus::Success;
    }
};

template<typename TReadIter, typename TWriteIter>
class StatusMessage : public Message<TReadIter, TWriteIter>
{
    using Base = Message<TReadIter, TWriteIter>;
    using Base::ReadIterator;
    using Base::WriteIterator;
protected:
    virtual ErrorStatus readimpl(TReadIter& iter, std::size_t len) override{
        cout<<"reading status"<<endl;
        return ErrorStatus::Success;
    }
    virtual ErrorStatus writeimpl(TWriteIter& iter, std::size_t len) override{
        return ErrorStatus::Success;
    }
};
#endif //PROJECT1_MESSAGE_H
