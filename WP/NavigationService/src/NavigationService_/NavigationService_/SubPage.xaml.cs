using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Microsoft.Phone.Controls;

namespace NavigationService_
{
    public partial class SubPage : PhoneApplicationPage
    {
        public SubPage()
        {
            InitializeComponent();
        }
        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            string msg;

            base.OnNavigatedTo(e);
            
            if (NavigationContext.QueryString.TryGetValue("msg", out msg))
            {
                textBlock2.Text = "msg = " + msg;
            }
        }
    }
}