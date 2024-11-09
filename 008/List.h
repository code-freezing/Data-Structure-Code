#pragma once

struct Node {
    Node* next;
    int value;
    Node(int val) :value(val), next(nullptr) {}
};

bool isCircularLinkedList(Node* head);