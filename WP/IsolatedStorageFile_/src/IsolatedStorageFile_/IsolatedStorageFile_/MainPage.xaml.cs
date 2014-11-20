using System;
using System.Collections.Generic;
using System.IO.IsolatedStorage;
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

namespace IsolatedStorageFile_
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
            IsolatedStorageFile storage = null;
            IsolatedStorageFileStream stream = null;
            try
            {
                storage = IsolatedStorageFile.GetUserStoreForApplication();
                stream = storage.CreateFile(textBox1.Text);
                if (storage.FileExists(textBox1.Text))
                {
                    MessageBox.Show("IsolatedStorageFile_ [" + textBox1.Text + "] Created!");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.ToString());
            }
            finally
            {
                if (storage.FileExists(textBox1.Text))
                {
                    stream.Close();
                    storage.DeleteFile(textBox1.Text);
                }
            }
        }
    }
}