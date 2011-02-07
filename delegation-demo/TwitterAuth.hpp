#ifndef TWITTER_AUTH_HPP
#define TWITTER_AUTH_HPP

#include <iostream>
#include <cstdio>
#include <string>

  // @Protocol TwitterAuthDelegate
class TwitterAuthDelegate {
  public:
    virtual void authenticationSuccessful() { }
    virtual void authenticationFailed() { }
    virtual void tweetSuccess() { }
    virtual void tweetFailed() { }
};

  // @Class TwitterAuth
class TwitterAuth {
  public:
    TwitterAuth() : delegate_(NULL) { }
    virtual ~TwitterAuth() { }

      // setDelegate
    void setDelegate( TwitterAuthDelegate* delegate ) {
      delegate_ = delegate;
    }

      // loginWithUsernameAndPassword
    void loginWithUsernameAndPassword(std::string username, std::string password)
    {
      if ( asynchronousLogin(username, password) ) {
        if ( delegate_ != NULL )
          delegate_->authenticationSuccessful();
      }
      else {
        if ( delegate_ != NULL )
          delegate_->authenticationFailed();
      }
    }

      // postTweet
    void postTweet(std::string text)
    {
      if ( asynchronousPostTweet(text) ) {
        if ( delegate_ != NULL )
          delegate_->tweetSuccess();
      }
      else {
        if ( delegate_ != NULL )
          delegate_->tweetFailed();
      }
    }

      // reTweet
    void reTweet(long int uuid) {
      if ( asynchronousReTweet(uuid) ) {
        if ( delegate_ != NULL )
          delegate_->tweetSuccess();
      }
      else {
        if ( delegate_ != NULL )
          delegate_->tweetFailed();
      }
    }

    TwitterAuthDelegate *delegate_;

  private:
    bool asynchronousLogin(std::string username, std::string password) {
      // ...
      return ( (float)((float)rand()/(float)RAND_MAX) < 0.5f );
    }

    bool asynchronousPostTweet(std::string text) {
      // ...
      return ( (float)((float)rand()/(float)RAND_MAX) < 0.5f );
    }

    bool asynchronousReTweet(long int uuid) {
      // ...
      return ( (float)((float)rand()/(float)RAND_MAX) < 0.5f );
    }
};

#endif