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

namespace Canvas_
{
    public partial class MainPage : PhoneApplicationPage
    {
        // コンストラクター
        public MainPage()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            textBlock1.Text = "Canvas Button1 Clicked!";
        }

        private void button2_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Canvas Button2 Clicked! and TextBox1 Text = " + textBox1.Text);
        }
    }
}