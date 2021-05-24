class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
    assert(!deck.empty());
    sort(deck.rbegin(), deck.rend()); 
    deque<int> deq;
    deq.push_back(deck[0]);
    for (int i = 1; i < deck.size(); i++) 
    {   deq.push_front(deq.back());
        deq.pop_back();
        deq.push_front(deck[i]);
    }
    return vector<int> (deq.begin(), deq.end());
    }
};