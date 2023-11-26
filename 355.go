package main

import (
	"sort"
)

type Twitter struct {
	Posts    map[int][]Post
	Follower map[int]map[int]struct{}
	Cnt      int
}
type Post struct {
	Time int
	Id   int
}

func Constructor() Twitter {
	return Twitter{map[int][]Post{}, map[int]map[int]struct{}{}, 0}
}

func (this *Twitter) PostTweet(userId int, tweetId int) {
	this.Posts[userId] = append(this.Posts[userId], Post{this.Cnt, tweetId})
	this.Cnt++
}

func (this *Twitter) GetNewsFeed(userId int) []int {
	posts := []Post{}
	for _, v := range this.Posts[userId] {
		posts = append(posts, v)
	}
	for k := range this.Follower[userId] {
		for _, v := range this.Posts[k] {
			posts = append(posts, v)
		}
	}
	sort.Slice(posts, func(i, j int) bool {
		return posts[i].Time > posts[j].Time
	})
	ans := []int{}
	for i := 0; i < len(posts) && i < 10; i++ {
		ans = append(ans, posts[i].Id)
	}
	return ans
}

func (this *Twitter) Follow(followerId int, followeeId int) {
	if this.Follower[followerId] == nil {
		this.Follower[followerId] = make(map[int]struct{})
	}
	this.Follower[followerId][followeeId] = struct{}{}
}

func (this *Twitter) Unfollow(followerId int, followeeId int) {
	delete(this.Follower[followerId], followeeId)
}
