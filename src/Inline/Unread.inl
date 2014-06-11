//WBOPT_GET_REMIND_UNREAD_COUNT,//��ȡĳ���û��ĸ�����Ϣδ����
//WBOPT_POST_STATUSES_RESET_COUNT,//������Ϣδ����

eWeiboResultCode SDKMethodImpl::getRemindUnreadCount(const char* uid, UserTaskInfo* pTask)
{
	DebugLog(<< __FUNCTION__ );

	if (Util::StringUtil::NullOrEmpty(uid))
	{
		return WRC_USERID_NULL;
	}

	std::string param;
	SDKHelper::setParam(param, "&uid", uid, PARAM_ENCODE_UTF8);

	WeiboRequestPtr ptr = internalMakeWeiboRequest(WBOPT_GET_REMIND_UNREAD_COUNT,
		param, getUnifiedFormat(), httpengine::HM_GET, pTask);

	return internalEnqueue(ptr); 
}

eWeiboResultCode SDKMethodImpl::postStatusesResetCount(const int type, UserTaskInfo* pTask)
{
	DebugLog(<< __FUNCTION__ );

	std::string param;
	SDKHelper::setIntParam(param, "&type", type);

	WeiboRequestPtr ptr = internalMakeWeiboRequest(WBOPT_POST_STATUSES_RESET_COUNT,
		param, getUnifiedFormat(), httpengine::HM_POST, pTask);

	return internalEnqueue(ptr); 
}
