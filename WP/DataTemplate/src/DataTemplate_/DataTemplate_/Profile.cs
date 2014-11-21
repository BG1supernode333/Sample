using System;
using System.Collections.Generic;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;

namespace DataTemplate_
{
    public class Profile
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public string Address { get; set; }
    }
    public class ProfileList
    {
        public List<Profile> Profiles { get; set; }
        public ProfileList()
        {
            Profiles = new List<Profile>
            {
                new Profile{ Name = "Taro", Age = 20, Address = "Tokyo"},
                new Profile{ Name = "Jiro", Age = 18, Address = "Osaka"},
                new Profile{ Name = "Saburo", Age = 17, Address = "Nagoya"},
                new Profile{ Name = "Shiro", Age = 16, Address = "Fkuoka"},
                new Profile{ Name = "Goro", Age = 15, Address = "Sapporo"}
            };
        }
    }
}
