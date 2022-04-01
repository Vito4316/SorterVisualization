//
// Created by vito on 01/04/2022.
//

#include "SortStatusFIFO.h"

SortStatus SortStatusFIFO::nextStatus() {
    if(completed && status < stack.size()) return stack[status++];
    if(completed && status >= stack.size()) return stack[status-1];
    return {};
}

void SortStatusFIFO::pushStatus(const SortStatus& x) {
    stack.push_back(x);
}

bool SortStatusFIFO::isCompleted() {
    return completed;
}

void SortStatusFIFO::setCompleted(bool x) {
    completed = x;
}
