#ifndef TWITTER_CLIENT_HPP
#define TWITTER_CLIENT_HPP

#include <string>
#include "TwitterAuth.hpp"

class Twitter : public TwitterAuthDelegate {
  public:
    Twitter(std::string username = "foo", std::string password = "bar") : username_(username), password_(password) {
      twitterAuth.setDelegate(this);
    }

    virtual ~Twitter() { }

    void login() {
      twitterAuth.loginWithUsernameAndPassword(username_, password_);
    }

    void tweet(std::string text) {
      tweetText = text;
      twitterAuth.postTweet(text);
    }

    /*
    * @Protocol TwitterAuthDelegate
    *  - authenticationSuccessful();
    */
    void authenticationSuccessful() {
      std::cout << "Successfully received OAuth tokens for " << username_ << ":" << password_ << "\n";
    }

    /*
    * @Protocol TwitterAuthDelegate
    *  - authenticationFailed();
    */
    void authenticationFailed() {
      std::cout << "Failed to receive tokens!\n";
    }

    /*
    * @Protocol TwitterAuthDelegate
    *  - tweetSuccessful();
    */
    void tweetSuccess() { 
      std::cout << "Successfully posted tweet \"" << tweetText << "\" as " << username_ << ":" << password_ << "\n";
    }

    /*
    * @Protocol TwitterAuthDelegate
    *  - tweetFailed();
    */
    void tweetFailed() {
      std::cerr << "Failed to post tweet \"" << tweetText << "\" as " << username_ << ":" << password_ << "\n";
    }

  private:
    TwitterAuth twitterAuth;
    std::string username_, password_;
    std::string tweetText;
};

#endif