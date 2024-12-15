using System;

class Program()
{

    static void Main()
    {
        int[] spieshecker = new int[] { 299, 799, 501, 511, 542, 575, 525, 527, 502, 574, 551, 536, 529, 545, 577, 503, 504, 581, 582, 524, 543, 544, 506, 530, 531, 507, 535, 523, 533, 505, 532, 521, 528, 578, 522, 538, 553, 554, 555, 547, 552, 520, 556, 515, 560, 516, 518, 509, 557, 549, 514, 508, 513, 558, 517, 510, 579, 576, 591, 570, 586, 589, 595, 594, 571, 564, 592, 572, 593, 561, 563, 587, 568, 596, 597, 584, 583, 598, 585 };

        int[] standox = new int[] { 599, 8, 570, 870, 810, 851, 564, 563, 571, 854, 897, 566, 576, 896, 856, 857, 816, 583, 883, 586, 561, 861, 567, 882, 582, 815, 579, 580, 577, 574, 581, 884, 575, 587, 573, 589, 588, 859, 562, 885, 585, 569, 855, 818, 893, 595, 594, 892, 812, 813, 590, 891, 593, 811, 819, 598, 806, 895, 801, 829, 836, 841, 805, 804, 831, 828, 802, 824, 803, 823, 825, 839, 821, 826, 827, 844, 843, 846, 845 };

        //Console.WriteLine(spieshecker.Length);
        //Console.WriteLine(standox.Length);
        ConsoleKeyInfo info = Console.ReadKey();
        info = Console.ReadKey();
        while (info.Key != ConsoleKey.Spacebar)
        {
            Console.Write("Введите номер компонента: ");
            string a = Console.ReadLine();
            int b = Convert.ToInt32(a);
            bool status = false;
            for (int i = 0; i < spieshecker.Length; i++)
            {
                if (spieshecker[i] == b)
                {
                    Console.WriteLine(standox[i]);
                    status = true;
                    break;
                }
            }
            if (!status)
            {
                Console.WriteLine("Такого компонента нет");
            }


        }
    }
}