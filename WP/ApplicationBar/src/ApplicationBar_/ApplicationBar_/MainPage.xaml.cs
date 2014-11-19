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
using System.Windows.Shapes;
using Microsoft.Phone.Controls;

namespace ApplicationBar_
{
    public partial class MainPage : PhoneApplicationPage
    {
        // コンストラクター
        public MainPage()
        {
            InitializeComponent();
        }

        private void ApplicationBarIconButton1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("ApplicationBarIconButton1 Clicked!");
        }

        private void ApplicationBarIconButton2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("ApplicationBarIconButton2 Clicked!");
        }

        private void ApplicationBarMenuItem1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("ApplicationBarMenuItem1 Clicked!");
        }

        private void ApplicationBarMenuItem2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("ApplicationBarMenuItem2 Clicked!");
        }
    }
}