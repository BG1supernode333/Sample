using System;
using System.Collections.Generic;
using System.IO;
using System.IO.IsolatedStorage;
using System.Linq;
using System.Net;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using Microsoft.Phone.Controls;

namespace IsolatedStorageFileStream_
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
            StreamReader sr = null;

            try
            {
                storage = IsolatedStorageFile.GetUserStoreForApplication();
                if (!storage.FileExists(textBox1.Text))
                {
                    MessageBox.Show("File Not Found!");
                    return;
                }
                stream = storage.OpenFile(textBox1.Text, FileMode.Open);
                sr = new StreamReader(stream, Encoding.UTF8);
                textBox2.Text = "";

                textBox2.Text = sr.ReadToEnd();  

                sr.Close();
                stream.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Load Error!: " + ex.ToString());
            }
            finally
            {
                if (sr != null)
                {
                    sr.Close();
                }
                if (stream != null)
                {
                    stream.Close();
                }
            }
        }

        private void button2_Click(object sender, RoutedEventArgs e)
        {
            IsolatedStorageFile storage = null;
            IsolatedStorageFileStream stream = null;
            StreamWriter sw = null;

            try
            {
                storage = IsolatedStorageFile.GetUserStoreForApplication();
                stream = storage.OpenFile(textBox1.Text, FileMode.Create);
                sw = new StreamWriter(stream, Encoding.UTF8);

                sw.Write(textBox2.Text);

                sw.Close();
                stream.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Save Error!: " + ex.ToString());
            }
            finally
            {
                if (sw != null)
                {
                    sw.Close();
                }
                if (stream != null)
                {
                    stream.Close();
                }
            }
        }
    }
}