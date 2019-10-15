#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Tweet {
public:
    int id;
    int user_id;
    string text;
    static Tweet create(int user_id, string tweet_text) {
        // This will create a new tweet object,
        // and auto fill id
    }
};

class MiniTwitter {
public:
    vector<Tweet> tweet_list;
    map<int,vector<int> > friend_list;
    MiniTwitter() {
        // do intialization if necessary
    }

    Tweet postTweet(int user_id, string &tweet_text) {
        Tweet t = Tweet::create(user_id,tweet_text);
        tweet_list.push_back(t);
        return t;
    }

    vector<Tweet> getNewsFeed(int user_id) {
        vector<Tweet> result;
        int length = tweet_list.size();
        for (int i = length-1;i >= 0;i--) {
            if (result.size() < 10) {
                if (tweet_list[i].user_id == user_id) {
                    result.push_back(tweet_list[i]);
                }
                else {
                    map<int,vector<int> >::iterator it = friend_list.find(user_id);
                    if (it != friend_list.end()) {
                        vector<int>::iterator itt = find(friend_list[user_id].begin(),friend_list[user_id].end(),tweet_list[i].user_id);
                        if (itt != friend_list[user_id].end()) {
                            result.push_back(tweet_list[i]);
                        }
                    }
                }
            }
            else {
                return result;
            }
        }
        return result;
    }

    vector<Tweet> getTimeline(int user_id) {
        vector<Tweet> result;
        int length = tweet_list.size();
        for (int i = length-1;i >= 0;i--) {
            if (result.size() < 10) {
                if (tweet_list[i].user_id == user_id) {
                    result.push_back(tweet_list[i]);
                }
            }
            else {
                return result;
            }
        }
        return result;
    }

    void follow(int from_user_id, int to_user_id) {
        map<int,vector<int> >::iterator it = friend_list.find(from_user_id);
        if (it != friend_list.end()) {
            vector<int>::iterator itt = find(friend_list[from_user_id].begin(),friend_list[from_user_id].end(),to_user_id);
            if (itt == friend_list[from_user_id].end()) {
                friend_list[from_user_id].push_back(to_user_id);
            }
        }
        else {
            friend_list[from_user_id].push_back(to_user_id);
        }
    }

    void unfollow(int from_user_id, int to_user_id) {
        map<int,vector<int> >::iterator it = friend_list.find(from_user_id);
        if (it != friend_list.end()) {
        for (vector<int>::iterator iter = friend_list[from_user_id].begin();iter != friend_list[from_user_id].end();) {
            if (*iter == to_user_id) {
                iter = friend_list[from_user_id].erase(iter);
            }
            else {
                iter ++;
            }
        }
        }
    }
};

int main() {
    return 0;
}
