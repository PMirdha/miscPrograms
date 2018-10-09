class TweetClass(object):
	def __init__(self):
		self.user_twt_num = dict()
		self.max_twt = 0
		self.max_user_list = list()
	
	def set_user_tweet(self,twt_str):
		user,tweet_id = twt_str.split(" ")
		if self.user_twt_num.get(user,None):
			self.user_twt_num[user] += 1
		else:
			self.user_twt_num[user] = 1

		if self.max_twt < self.user_twt_num[user]:
			self.max_twt=self.user_twt_num[user]
			self.max_user_list = []
			self.max_user_list.append(user)
		elif self.max_twt == self.user_twt_num[user]:
			self.max_user_list.append(user)
	
	def print_max_tweet(self):
		sorted_user = sorted(self.max_user_list)
		for user in sorted_user:
			print(str(user)+" "+str(self.max_twt))


def get_input():
	n=int(raw_input())
	twt_obj = TweetClass()
	for x in xrange(0,n):
		twt_str = raw_input()
		twt_obj.set_user_tweet(twt_str)
	twt_obj.print_max_tweet()

if __name__ == '__main__':
	t=int(raw_input())
	while t:
		get_input()
		t -= 1