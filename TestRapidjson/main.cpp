//
//  main.cpp
//  TestRapidjson
//
//  Created by xugang on 8/10/14.
//  Copyright (c) 2014 RongCloud. All rights reserved.
//

#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/filestream.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
//#include "rapidjson/reader.h"

//using namespace std;
//using namespace rapidjson;

//#include "JsonStream.h"

const char* jsonSource(){
    rapidjson::Document document;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocator = document.GetAllocator();
    
    //定义一个数组
    rapidjson::Value dataArray;
    dataArray.SetArray();
    
    const char * p_name ="xugang";
    
    for (int i=0; i<5; i++) {
        
        rapidjson::Value member;
        member.SetObject();
        
        member.AddMember("name", rapidjson::Value().SetString(p_name, allocator), allocator);
        member.AddMember("age", i, allocator);
        member.AddMember("phone", "18611797081", allocator);
        dataArray.PushBack(member, allocator);
        
    }
    
    document.AddMember("personList", dataArray, allocator);
    
    rapidjson::StringBuffer buffer;
    rapidjson:: Writer<rapidjson::StringBuffer> writer(buffer);
    
    
    document.Accept(writer);
    
    
    char* returnData = new char[buffer.Size()+1];
    strcpy(returnData,buffer.GetString());
    
    // *result = returnData;
    
   
    
    
    return returnData;
}

int main(int argc, const char * argv[])
{
    
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
//    printf("Lu//a\"\n");
//	Document document;
//	
//	Document::AllocatorType & allocator = document.GetAllocator();
//	Value contact(kArrayType);
//	Value contact2(kArrayType);
//	Value root(kArrayType);
//    
//    
//	contact.PushBack("Lu//a\"", allocator).PushBack("Mio", allocator).PushBack("", allocator);
//	contact2.PushBack("Lu// a", allocator).PushBack("Mio", allocator).PushBack("", allocator);
//	root.PushBack(contact, allocator);
//	root.PushBack(contact2, allocator);
//    
//	StringBuffer buffer;
//	Writer<StringBuffer> writer(buffer);
//	root.Accept(writer);
//	string reststring = buffer.GetString();
//	cout << reststring << endl;
	
    
    const char* p = jsonSource();
    
    printf("%s\n",p);
    

    rapidjson::Document doc;
   
    
    doc.Parse<0>(p).HasParseError();
    
    rapidjson::Value &dataArray = doc["personList"];
    
    if (dataArray.IsArray()) {
        int i =0;
        rapidjson::Value &first = dataArray[i];
        rapidjson::Value &name = first["name"];
        printf("name==>%s\n",name.GetString());
        
    }
  
    
    
    
    
    
    return 0;
}

